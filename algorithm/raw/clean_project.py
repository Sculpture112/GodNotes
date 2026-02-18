import os
import re
from pathlib import Path

def clean_filename(title):
    # Remove invalid filename characters
    title = re.sub(r'[\/:*?"<>|]', '', title)
    # Remove leading/trailing whitespace and limit length
    title = title.strip()[:100]
    if not title:
        return "untitled"
    return title

def is_garbage_content(content):
    # Check if content is empty or only whitespace
    if not content.strip():
        return True
    
    # Check if content is just a broken image link like ![]() or ![...](...)
    # and has no other substantial text
    lines = [l.strip() for l in content.split('
') if l.strip()]
    if len(lines) <= 2:
        # If it's just one or two lines, check if they are all image tags
        all_images = all(re.match(r'^!\[.*?\]\(.*?\)$', line) for line in lines)
        if all_images:
            return True
            
    return False

def process_files():
    p = Path('.')
    markdown_files = list(p.glob('*.md'))
    
    deleted_count = 0
    renamed_count = 0
    error_count = 0

    for file_path in markdown_files:
        filename = file_path.name
        
        # 1. Deletion Logic
        if filename.startswith('![image'):
            try:
                file_path.unlink()
                print(f"Deleted (filename pattern): {filename}")
                deleted_count += 1
                continue
            except Exception as e:
                print(f"Error deleting {filename}: {e}")
                error_count += 1
                continue

        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()
            
            if is_garbage_content(content):
                file_path.unlink()
                print(f"Deleted (garbage content): {filename}")
                deleted_count += 1
                continue
                
            # 2. Renaming Logic
            # Extract first line or core title
            lines = [l.strip() for l in content.split('
') if l.strip()]
            if not lines:
                continue
            
            # Look for # Header or just use the first line
            new_title = lines[0]
            for line in lines:
                if line.startswith('#'):
                    new_title = line.lstrip('#').strip()
                    break
                elif len(line) > 2: # First substantial line
                    new_title = line
                    break
            
            clean_title = clean_filename(new_title)
            new_filename = f"{clean_title}.md"
            
            if new_filename != filename:
                new_path = file_path.with_name(new_filename)
                
                # Check for collision
                if new_path.exists():
                    # If it's the same content (case insensitive check on some OS), skip
                    if filename.lower() == new_filename.lower():
                        # On Windows, renaming a.md to A.md is tricky, but Path.rename usually handles it or errors
                        pass
                    else:
                        # Append a suffix if conflict exists
                        counter = 1
                        while new_path.exists():
                            new_path = file_path.with_name(f"{clean_title}_{counter}.md")
                            counter += 1
                
                file_path.rename(new_path)
                print(f"Renamed: {filename} -> {new_path.name}")
                renamed_count += 1
                
        except Exception as e:
            print(f"Error processing {filename}: {e}")
            error_count += 1

    print(f"
Summary: Deleted {deleted_count}, Renamed {renamed_count}, Errors {error_count}")

if __name__ == "__main__":
    process_files()
