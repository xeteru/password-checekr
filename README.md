a program that checks how strong a password based on the length of the password, the amount of special characters, the amount of letters, the amount of numbers, and the variety of the characters in the password

precedence
1-special characters
2-letters
3-numbers
4-length

make it where the strength have updates that is printed on a character to character basis

make an algorithm that quantifies randomness in a password

try bst

try a text file with a lot of words

# Unicode Rendering [POWERSHELL]

```powershell
$OutputEncoding = [console]::InputEncoding = [console]::OutputEncoding =
                    New-Object System.Text.UTF8Encoding
```
Set text encoding to UTF-8. [Source](https://stackoverflow.com/questions/40098771/changing-powershells-default-output-encoding-to-utf-8)