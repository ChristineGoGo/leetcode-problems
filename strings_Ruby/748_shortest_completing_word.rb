=begin
Given a string licensePlate and an array of strings words, find the shortest completing word in words.

A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.

For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".

Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

 

Example 1:

Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
Output: "steps"
Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
"step" contains 't' and 'p', but only contains 1 's'.
"steps" contains 't', 'p', and both 's' characters.
"stripe" is missing an 's'.
"stepple" is missing an 's'.
Since "steps" is the only word containing all the letters, that is the answer.

Example 2:

Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
Output: "pest"
Explanation: licensePlate only contains the letter 's'. All the words contain 's', but among these "pest", "stew", and "show" are shortest. The answer is "pest" because it is the word that appears earliest of the 3.

 

Constraints:

    1 <= licensePlate.length <= 7
    licensePlate contains digits, letters (uppercase or lowercase), or space ' '.
    1 <= words.length <= 1000
    1 <= words[i].length <= 15
    words[i] consists of lower case English letters.


=end

# @param {String} license_plate
# @param {String[]} words
# @return {String}
def shortest_completing_word(license_plate, words)
    plate_dictionary = {}
    word_dictionary = {}
    n = 0

    license_plate.each_char { |character|
        character = character.downcase
        if plate_dictionary[character] == nil
            plate_dictionary[character] = 1
        else
            plate_dictionary[character] += 1
        end

    }

    words.each { |word|
        word_size = word.size
        word.each_char { |letter|
            letter = letter.downcase
            if word_dictionary[letter] == nil
                word_dictionary[letter] = 1
            else
                word_dictionary[letter] += 1
            end
            
            if n == word_size
                plate_dictionary.each_pair { |key, value|
                    if word_dictionary[key] != value
                        n = 0
                        continue
                    end 
                }
            end
            if n == word_size
                return word
            end

            n += 1
        }

    }
end