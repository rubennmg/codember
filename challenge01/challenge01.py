words_list = []
word = ""
result= ""

with open("message01.txt", "r") as file:
    content = file.read()
    words = content.split(" ")
    for word in words:
        if word not in words_list:
            words_list.append(word.lower()) 
    for saveword in words_list:
        i = 0
        for word in words:
            if saveword == word.lower():
                i += 1
        result += saveword + str(i)
        i = 0
      
print(result)

    
