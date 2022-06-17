# Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the 
# letters from magazine and false otherwise.

# Each letter in magazine can only be used once in ransomNote.

# @param {String} ransom_note
# @param {String} magazine
# @return {Boolean}
# ----------------------------------- APPROACH 1 --------------------------------
=begin
def can_construct(ransom_note, magazine)
   r = ransom_note.split("")
   r.each { |c|
      if magazine.include?(c)
         magazine.slice!(magazine.rindex(c))
      else
         return false
      end
   }
   return true
end
=end
# ----------------------------------- APPROACH 2 --------------------------------
# 2 HASH MAPS
def can_construct(ransom_note, magazine)
   ransom_hash = hash_creator({}, ransom_note)
   magazine_hash = hash_creator({}, magazine)
   ransom_hash.each_pair { |key, value|
      magazine_key = magazine_hash[key]
      if (magazine_key && magazine_key < value) || !magazine_key
         return false
      end
   }
   return true
end

def hash_creator(h, word)
   word.each_char {|c| 
      if h[c]
         h[c] += 1
      else
         h[c] = 1
      end
   }
   return h
end
# test 1
# puts can_construct("cat", "dog")
# test 2
# puts can_construct("aab", "baa")
# test 3
# puts can_construct("cookbook", "cookie")
# test 4
# puts can_construct("shoe", "shoobadobadoee")

# test 5
puts can_construct("a", "shoo")
