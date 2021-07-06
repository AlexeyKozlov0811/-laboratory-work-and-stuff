import pymysql
from datetime import datetime
import csv


def get_application_status_by_id(application_id):
    try:
        connection = pymysql.connect(
            host="localhost",
            port=3306,
            user="user",
            password="password",
            database="test",
            cursorclass=pymysql.cursors.DictCursor
        )
        print("Connection successful")
        try:
            with connection.cursor() as cursor:
                select_all_rows = "SELECT * FROM `applications` WHERE `application_id`=%s"
                execution_time = datetime.time(datetime.now()).strftime("%H:%M:%S")
                cursor.execute(select_all_rows, (application_id,))
                result = cursor.fetchone()
                result.update({'created_at': execution_time})
                print(result)
                write_dict_to_csv(result)
        finally:
            connection.close()

    except Exception as ex:
        print("Connection failure")
        print(ex)


def write_dict_to_csv(dictionary):
    with open('task_1.csv', 'w') as File:
        fieldnames = dictionary
        writer = csv.DictWriter(File, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerow(dictionary)


get_application_status_by_id(15550)
