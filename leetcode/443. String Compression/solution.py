class Solution:
    def updateChars(self, chars: list[str], writer:int, char:str, counter:int) -> tuple[list[str], int]:
        
        chars[writer] = char
        writer += 1

        if counter == 1:
            return chars, writer

        countvals: list[str] = []

        while counter > 0:
            countvals.insert(0, str(counter % 10))
            counter = counter // 10
        
        for i in countvals:
            chars[writer] = i
            writer += 1

        return chars, writer


    def compress(self, chars: list[str]) -> int:
        
        writer = 0
        reader = 1
        counter = 1
        char = chars[0]

        while reader < len(chars):
            
            if char != chars[reader]:
                chars, writer = self.updateChars(chars, writer, char, counter)
                counter = 1
            else:
                counter += 1

            if reader < len(chars):
                char = chars[reader]
            reader += 1
                    
        chars, writer = self.updateChars(chars, writer, char, counter)

        return writer