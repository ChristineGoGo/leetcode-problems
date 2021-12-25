def reformatDate(date):
    date_list = date.split(" ")
    new_date = []
    month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}
    # for i in range(len(date_list), 0, -1):
    #     if i == 2:
    #         new_date.append(date_list[i] + '-')
    #     elif i == 1:
    #         new_date.append(month[i])
    #     else:
    #         new_date.append(date_list[0])
    #
    # return new_date
    print(month)


if __name__ == '__main__':
    date = "20th Oct 2052"
    print(reformatDate(date))

