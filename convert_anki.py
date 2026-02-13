
import re
import os
import html

def html_to_markdown(html_content):
    # Decode HTML entities first
    html_content = html.unescape(html_content)

    # Convert code blocks: <pre>...</pre> to ```\n...\n```
    def replace_code_block(match):
        content = match.group(1)
        content = re.sub(r'</?span[^>]*>','', content)
        content = re.sub(r'</?div[^>]*>','', content)
        content = re.sub(r'<pre[^>]*>', '', content)
        content = re.sub(r'</pre>', '', content)
        content = re.sub(r'<code[^>]*>', '', content)
        content = re.sub(r'</code>', '', content)
        return "\n```cpp\n" + content.strip() + "\n```\n"

    html_content = re.sub(r'<pre[^>]*>(.*?)</pre>', replace_code_block, html_content, flags=re.DOTALL | re.IGNORECASE)
    html_content = re.sub(r'<code[^>]*>(.*?)</code>', replace_code_block, html_content, flags=re.DOTALL | re.IGNORECASE)

    # Convert images
    def replace_img(match):
        src = match.group('src')
        alt = match.group('alt') if 'alt' in match.groupdict() and match.group('alt') else os.path.basename(src)
        return f"![{alt}]({src})"

    # Handle double-quoted attributes
    html_content = re.sub(r'<img[^>]*src="(?P<src>[^"]+)"[^>]*alt="(?P<alt>[^"]*)"[^>]*>', replace_img, html_content, flags=re.IGNORECASE)
    html_content = re.sub(r'<img[^>]*alt="(?P<alt>[^"]*)"[^>]*src="(?P<src>[^"]+)"[^>]*>', replace_img, html_content, flags=re.IGNORECASE)
    html_content = re.sub(r'<img[^>]*src="(?P<src>[^"]+)"[^>]*>', replace_img, html_content, flags=re.IGNORECASE)

    # Handle single-quoted attributes
    html_content = re.sub(r"<img[^>]*src='(?P<src>[^']+)'[^>]*alt='(?P<alt>[^']*)'[^>]*>", replace_img, html_content, flags=re.IGNORECASE)
    html_content = re.sub(r"<img[^>]*alt='(?P<alt>[^']*)'[^>]*src='(?P<src>[^']+)'[^>]*>", replace_img, html_content, flags=re.IGNORECASE)
    html_content = re.sub(r"<img[^>]*src='(?P<src>[^']+)'[^>]*>", replace_img, html_content, flags=re.IGNORECASE)

    # Remove remaining HTML tags
    html_content = re.sub(r'<[^>]+>', '', html_content)

    # Replace multiple newlines
    html_content = re.sub(r'[\r\n]+', '\n', html_content).strip()

    return html_content

def sanitize_filename(text):
    s = re.sub(r'[\\/:*?"<>|]', '_', text)
    s = s.replace('\n', '_').replace('\r', '_').replace('\t', '_')
    return s[:50].strip('_')

def process_anki_file(input_file, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        print(f"Created directory: {output_dir}")

    with open(input_file, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    print(f"Read {len(lines)} lines from {input_file}")

    card_data = []
    start_index = 0
    for i, line in enumerate(lines):
        if not line.startswith('#'):
            start_index = i
            break
    
    print(f"Starting processing from line {start_index + 1}")

    for i, line in enumerate(lines[start_index:]):
        # Don't use strip() before split to preserve tabs if they are at the end
        parts = line.split('\t')
        if len(parts) >= 1:
            # If it starts and ends with quotes, it's likely a single column content
            content = parts[0].strip()
            if content.startswith('"') and content.endswith('"'):
                content = content[1:-1].replace('""', '"') # Unescape quotes
            
            if not content:
                continue

            markdown_content = html_to_markdown(content)
            card_data.append((markdown_content, i))

    print(f"Processed {len(card_data)} cards")

    filenames = set()
    for markdown_content, original_index in card_data:
        lines = [l for l in markdown_content.split('\n') if l.strip()]
        first_line = lines[0].strip() if lines else f"card_{original_index}"
        
        base_filename = sanitize_filename(first_line)
        if not base_filename or base_filename == '_':
            base_filename = f"card_{original_index}"

        filename = base_filename
        counter = 1
        while f"{filename}.md" in filenames:
            filename = f"{base_filename}_{counter}"
            counter += 1
        filenames.add(f"{filename}.md")

        output_path = os.path.join(output_dir, f"{filename}.md")
        with open(output_path, 'w', encoding='utf-8') as outfile:
            outfile.write(markdown_content)
    
    print(f"Done! Created {len(filenames)} files in {output_dir}")

if __name__ == "__main__":
    input_anki_file = "Algorithm.txt"
    output_markdown_dir = "algorithm/raw"
    process_anki_file(input_anki_file, output_markdown_dir)
