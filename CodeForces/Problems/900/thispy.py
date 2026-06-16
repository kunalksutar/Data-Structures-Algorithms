encoded_text = "æª”æ¡ˆå°æ‡‰"
# Use 'replace' to handle characters that cannot be encoded
decoded_text = encoded_text.encode('latin1', errors='replace').decode('utf-8', errors='replace')
print(decoded_text)
