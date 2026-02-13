import re
import os
import html
import csv
import sys

# Increase CSV field size limit for large Anki cards
csv.field_size_limit(sys.maxsize)

def html_to_markdown(html_content):
    if not html_content:
        return ""
    
    # DO NOT unescape at the beginning.
    # Anki HTML uses real tags for formatting and escaped characters for code.

    # Convert code blocks: <pre>...</pre> or <code>...</code> to ```\n...\n```
    def replace_code_block(match):
        content = match.group(1)
        # Remove internal HTML tags from code blocks (like syntax highlighting spans)
        content = re.sub(r'<[^>]+>', '', content)
        # We don't unescape yet, we'll do it at the very end.
        return "\n```cpp\n" + content.strip() + "\n```\n"

    html_content = re.sub(r'<pre[^>]*>(.*?)</pre>', replace_code_block, html_content, flags=re.DOTALL | re.IGNORECASE)
    html_content = re.sub(r'<code[^>]*>(.*?)</code>', replace_code_block, html_content, flags=re.DOTALL | re.IGNORECASE)

    # Convert images
    def replace_img(match):
        src = match.group('src')
        alt = match.group('alt') if 'alt' in match.groupdict() and match.group('alt') else os.path.basename(src)
        return f"![{alt}]({src})"

    # Handle double-quoted and single-quoted attributes
    patterns = [
        r'<img[^>]*src="(?P<src>[^"]+)"[^>]*alt="(?P<alt>[^"]*)"[^>]*>',
        r'<img[^>]*alt="(?P<alt>[^"]*)"[^>]*src="(?P<src>[^"]+)"[^>]*>',
        r'<img[^>]*src="(?P<src>[^"]+)"[^>]*>',
        r"<img[^>]*src='(?P<src>[^']+)'[^>]*alt='(?P<alt>[^']*)'[^>]*>",
        r"<img[^>]*alt='(?P<alt>[^']*)'[^>]*src='(?P<src>[^']+)'[^>]*>",
        r"<img[^>]*src='(?P<src>[^']+)'[^>]*>"
    ]
    for pattern in patterns:
        html_content = re.sub(pattern, replace_img, html_content, flags=re.IGNORECASE)

    # Convert <br> to newlines
    html_content = re.sub(r'<br\s*/?>', '\n', html_content, flags=re.IGNORECASE)
    
    # Convert <div> and </div> to newlines
    html_content = re.sub(r'</?div[^>]*>', '\n', html_content, flags=re.IGNORECASE)

    # Remove remaining HTML tags
    html_content = re.sub(r'<[^>]+>', '', html_content)

    # NOW unescape to turn &lt; into < etc.
    html_content = html.unescape(html_content)

    # Replace multiple newlines with at most two
    html_content = re.sub(r'\n\s*\n', '\n\n', html_content)
    return html_content.strip()

def sanitize_filename(text):
    # Remove common punctuation and characters that are bad for filenames
    s = re.sub(r'[\\/:*?"<>|#\t]', '_', text)
    # Replace multiple spaces/underscores
    s = re.sub(r'[\s_]+', '_', s)
    return s[:50].strip('_')

def process_anki_file(input_file, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    else:
        for f in os.listdir(output_dir):
            try:
                os.remove(os.path.join(output_dir, f))
            except:
                pass

    count = 0
    with open(input_file, 'r', encoding='utf-8') as f:
        reader = csv.reader(f, delimiter='\t', quotechar='"', doublequote=True)
        
        filenames = set()
        
        for i, row in enumerate(reader):
            if not row:
                continue
            if row[0].startswith('#'):
                continue
            
            # Use the first column as content
            content = row[0]
            if not content:
                continue
                
            markdown_content = html_to_markdown(content)
            if not markdown_content:
                continue
                
            # Filename
            lines = [l for l in markdown_content.split('\n') if l.strip()]
            first_line = lines[0].strip() if lines else f"card_{i}"
            if first_line.startswith('```'):
                if len(lines) > 1:
                    first_line = lines[1].strip()
            
            base_filename = sanitize_filename(first_line)
            if not base_filename or base_filename == '_':
                base_filename = f"card_{i}"

            filename = base_filename
            c_num = 1
            while f"{filename}.md" in filenames:
                filename = f"{base_filename}_{c_num}"
                c_num += 1
            filenames.add(f"{filename}.md")

            output_path = os.path.join(output_dir, f"{filename}.md")
            with open(output_path, 'w', encoding='utf-8') as outfile:
                outfile.write(markdown_content)
            count += 1

    print(f"Done! Processed {count} cards into {output_dir}")

if __name__ == "__main__":
    input_anki_file = "Algorithm.txt"
    output_markdown_dir = "algorithm/raw"
    process_anki_file(input_anki_file, output_markdown_dir)
