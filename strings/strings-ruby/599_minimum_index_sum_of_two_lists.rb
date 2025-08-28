# @param {String[]} list1
# @param {String[]} list2
# @retun {String[]}

def find_restaurant(list1, list2)
    l_sum = list1.size + list2.size
    result = []
    list1.each_with_index { |i, elem1| 
        list2.each_with_index { |j, elem2|
            if (i == j) 
                if  (elem1 + elem2 < l_sum)
                    result = []
                    l_sum = elem1 + elem2
                    result << i
                elsif (elem1 + elem2 == l_sum)
                    result << i
                end 
            end
        }
        # result = []
    }
    return result
end

puts find_restaurant(["dog", "cat", "panda"], ["cat", "dog", "horse"])
