import requests
import numpy as np
import pandas as pd


def get_age():
    r = requests.get('https://coderbyte.com/api/challenges/json/age-counting')
    content = r.json()
    values = content['data'].split(" ")
    ages = [value[4:-1] for value in values if 'age' in value and len(value) > 0]
    ages = [int(i) for i in ages if len(i) > 0]
    df = pd.DataFrame(ages)
    df.columns = ['ages']
    print(len(df[df['ages'] >= 50]))


if __name__ == '__main__':
    get_age()
