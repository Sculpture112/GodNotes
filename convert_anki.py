import re
import os
import html

def html_to_markdown(html_content):
    # Decode HTML entities first
    html_content = html.unescape(html_content)

    # Convert code blocks: <pre>...</pre> to ```
...
```
    # This needs to be done before stripping other tags
    def replace_code_block(match):
        # Extract content within <pre> or <code> tags, handling nested structures
        # This is a simplification; a full HTML parser would be more robust.
        # For our observed data, direct content extraction should work for many cases.
        content = match.group(1)
        # Try to clean up internal HTML tags if any, but keep content for now.
        content = re.sub(r'</?span[^>]*>','', content) # remove span tags
        content = re.sub(r'</?div[^>]*>','', content) # remove div tags
        content = re.sub(r'<pre[^>]*>', '', content) # remove opening pre
        content = re.sub(r'</pre>', '', content) # remove closing pre
        content = re.sub(r'<code[^>]*>', '', content) # remove opening code
        content = re.sub(r'</code>', '', content) # remove closing code
        # Attempt to infer language from preceding comments or context if available
        # For now, just use a generic code block.
        return "```cpp\n" + content.strip() + "\n```" # Assuming cpp based on observed data

    html_content = re.sub(r'<pre[^>]*>(.*?)</pre>', replace_code_block, html_content, flags=re.DOTALL | re.IGNORECASE)
    html_content = re.sub(r'<code[^>]*>(.*?)</code>', replace_code_block, html_content, flags=re.DOTALL | re.IGNORECASE)


    # Convert images: <img alt="..." src="..."> to ![alt](src)
    def replace_img(match):
        src = match.group('src')
        alt = match.group('alt') if match.group('alt') else os.path.basename(src)
        return f"![{alt}]({src})"

    # FIX START
    # Removed backslashes from inside the character class [^"']
    html_content = re.sub(r'<img[^>]*src=["\'](?P<src>[^"']+)["\'][^>]*alt=["\'](?P<alt>[^"']*)["\'][^>]*>', replace_img, html_content, flags=re.IGNORECASE)
    html_content = re.sub(r'<img[^>]*alt=["\'](?P<alt>[^"']*)["\'][^>]*src=["\'](?P<src>[^"']+)["\'][^>]*>', replace_img, html_content, flags=re.IGNORECASE)
    html_content = re.sub(r'<img[^>]*src=["\'](?P<src>[^"']+)["\'][^>]*>', replace_img, html_content, flags=re.IGNORECASE)
    # FIX END


    # Remove remaining HTML tags, but keep content
    html_content = re.sub(r'<[^>]+>', '', html_content)

    # Replace multiple newlines with single ones, and strip leading/trailing whitespace
    html_content = re.sub(r'[\r\n]+', '\n', html_content).strip()

    return html_content

def sanitize_filename(text):
    # Remove invalid characters for filenames
    s = re.sub(r'[\\/:*?"<>| ]', '_', text)
    # Trim to a reasonable length
    return s[:50].strip('_')

def process_anki_file(input_file, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    with open(input_file, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    card_data = []
    # Skip header lines if present
    start_index = 0
    if lines and lines[0].startswith('#separator'):
        for i, line in enumerate(lines):
            if not line.startswith('#'):
                start_index = i
                break
        lines = lines[start_index:]

    for i, line in enumerate(lines):
        parts = line.strip().split('\t')
        if len(parts) > 1:
            # Assuming the second part is the primary content
            html_content = parts[1]
            markdown_content = html_to_markdown(html_content)
            card_data.append((markdown_content, i)) # Store content and original line index

    filenames = set()
    for markdown_content, original_index in card_data:
        # Generate filename from the first meaningful part of the markdown content
        # Take the first line or first few words
        first_line = markdown_content.split('\n')[0].strip()
        if not first_line: # If first line is empty, try second line etc.
            first_line = markdown_content.split('\n')[1].strip() if len(markdown_content.split('\n')) > 1 else f"card_{original_index}"

        base_filename = sanitize_filename(first_line)
        if not base_filename: # Fallback if sanitization results in empty string
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
        print(f"Exported card {original_index+start_index+1} to {output_path}")

if __name__ == "__main__":
    input_anki_file = "Algorithm.txt"
    output_markdown_dir = "algorithm/raw"
    process_anki_file(input_anki_file, output_markdown_dir)
