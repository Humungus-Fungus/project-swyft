# This module is for connecting to my database and extracting data from it/inserting data into it
import pyodbc

conn = pyodbc.connect("DRIVER={SQL Server Native Client 11.0};UID=Svangulfur;WSID=COMPUTEROFSVANG;APP={Microsoft® Windows® Operating System};Trusted_Connection=Yes;SERVER=COMPUTEROFSVANG;Description=tutorial")
cursor = conn.cursor()
cursor.execute("SELECT Driver_Name FROM Driver WHERE Driver_ID = 1")

row = cursor.fetchone()
while row:
    print(row[0])
    row = cursor.fetchone()

cursor.close()
