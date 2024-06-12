# Wordle

> Simple console game written in c++

---

### Table of Contents

- [Description](#Description)
- [Algorithm](#Algorithm)
- [CodingGame screenshots](#CodingGame-Screenshots)
- [Test examples screenshots](#Test-examples-screenshots)
- [Test cases screenshots](#Test-cases-screenshots)

---

## Description
This is a simple console game where the player must guess a 5-character word. The game provides feedback on the guessed word:

- If a character is guessed correctly and is in the right position, it is highlighted in uppercase.
- If a character is guessed correctly but is in the wrong position, it is highlighted in lowercase.

The game supports two modes:

1. Wordle of the Day: Generates a word based on the current day.
2. Random Wordle: Generates a random word from a database.

## Algorithm

> bool CheckMatch(const std::string& PlayerWord, std::string& Word)

1. Init: MatchCount is set to 0, and Result is initialized to a string of 5 asterisks.

2. Iteration and Comparison:

The function iterates through each character of the Word (target word).
Each character in Word is converted to uppercase.

3. Exact Match Check:

For each character in Word, it checks if it matches the corresponding character in PlayerWord (considering both position and character).
If there is an exact match:
The corresponding position in Result is set to that character (in uppercase).
MatchCount is incremented.

4. Partial Match Check:

If there is no exact match for a character, it checks if the character in Word exists anywhere in PlayerWord and if the corresponding 
position in Result is still an asterisk.
If such a character is found:
The corresponding position in Result is set to the lowercase version of the matching character in PlayerWord.
This ensures that each character in PlayerWord is only matched once.

5. Output the Result:

The Result string is printed, showing the outcome of the comparison.
Characters that match exactly are shown in uppercase.
Characters that are in PlayerWord but in a different position are shown in lowercase.
Positions that do not match any character in Word remain as asterisks.

6. Return Value:

If MatchCount equals 5, meaning all characters match exactly, the function returns true.
Otherwise, it returns false.

---

## CodingGame screenshots

![CodingGames screenshot 1](https://i.ibb.co/c231ghD/2024-06-12-104227.png)

![CodingGames screenshot 2](https://i.ibb.co/hHY8zyc/2024-06-12-104309.png)

![CodingGames screenshot 3](https://i.ibb.co/vQXR3J4/2024-06-12-104338.png)

---

## Test examples screenshots

![Test examples screenshot 1](https://i.ibb.co/z6zyCpk/2024-06-12-105230.png)

![Test examples screenshot 2](https://i.ibb.co/StMxKxy/2024-06-12-105330.png)

![Test examples screenshot 3](https://i.ibb.co/k0Cb0fD/2024-06-12-105515.png)

![Test examples screenshot 4](https://i.ibb.co/vxcS8vF/2024-06-12-105539.png)

## Test cases screenshots

Test case "Hello"
![Test cases screenshots 1](https://i.ibb.co/KWFNBG0/2024-06-12-104651.png)

Test case "Cocon"
![Test cases screenshots 2](https://i.ibb.co/72cyz4G/2024-06-12-104822.png)

Test case "Speak"
![Test cases screenshots 3](https://i.ibb.co/88syCyn/2024-06-12-105009.png)