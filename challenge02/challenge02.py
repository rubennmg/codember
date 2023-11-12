result = ''
i = 0

with open('message02.txt', 'r') as f:
    content = f.read()
    for c in content:
        if c == '#':
            i = i + 1 
        elif c == '@':
            i = i -1
        elif c == '*':
            i = i * i
        if c == '&':
            result = result + str(i)
            
print(result)
             
