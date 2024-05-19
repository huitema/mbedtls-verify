# Python
lines = []
for line in open("key-data.txt", "r"):
    lines.append(line.strip())

i = 0
while i < len(lines):
    s = ""
    for j in range(0,16):
        if i >= len(lines):
            break
        s += lines[i]
        i += 1
    print(s)


