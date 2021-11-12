import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('iris.csv')
#print(df.head())
ls = ['Iris-versicolor','Iris-virginica']
res = df[df['Class'].isin(ls)]
print(res[["Class","Sepal_Width"]])
print( pd.crosstab(res.Sepal_Width,res.Class))