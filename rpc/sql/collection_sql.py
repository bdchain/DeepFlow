import os
import sys
import glob
import numpy as np
import pymysql as mysql

mysql_host = "127.0.0.1"
mysql_port = 1891
db         = "block"
test_db    = "test"
user       = "root"
password   = "Rootali1"
table_all_in_one = "collection_all"

def get_connection():
    conn = mysql.connect(
        host=mysql_host, port=mysql_port, db=db, user=user, password=password
    )
    print("Connection established!")
    return conn

def close_connection(conn):
    conn.close()
    print("Disconnect to the db!")

# IDs which are encrypted by SHA256
# are saved by readable text
# which takes 64 bytes for each ID
def create_table(conn, start_height):
    cursor = conn.cursor()
    sql = f"CREATE TABLE {table_all_in_one} ("\
        f"ID CHAR(64) PRIMARY KEY,"\
        f"TransactionNum SMALLINT UNSIGNED NOT NULL,"\
        f"Transactions TEXT"\
        f")"

    cursor.execute(sql)
    cursor.close()
    print("Table created successfully!")
    return table_all_in_one
    
def insert_table(conn, data, table_name):
    cursor = conn.cursor()
    for entry in data:
        sql = f"INSERT INTO {table_name} "\
            f"(ID, TransactionNum, Transactions) "\
            f"VALUES "\
            f"("\
            f"{entry[0]}, '{entry[1]}', '{entry[2]}', "\
            f"'{entry[3]}', {entry[4]}, {entry[5]}, '{entry[6]}'"\
            f")"
        result = cursor.execute(sql)
        assert result == 1
    conn.commit()
    cursor.close()
    print(f"Insert data into table {table_name} successfully!")

def parse_data(data_path):
    cwd = os.getcwd()
    os.chdir(data_path)
    # Find Block file in <data_path>
    matched_files = glob.glob("Blocks_*_*.csv")
    assert len(matched_files) == 1
    data = []
    data_file = matched_files[0]
    with open(data_file, "r") as rf:
        for line in rf.readlines():
            line = line.rstrip()
            cols = line.split(',')

            id = cols[0]
            parent_id = cols[1]
            timestamp = cols[2]
            height = int(cols[3])
            seal_num = int(cols[4])
            collection_num = int(cols[5])

            entry = [height, id, parent_id, timestamp, seal_num, collection_num]
            packed_collections = ""
            for i in range(collection_num):
                packed_collections += cols[i+6]
            assert len(packed_collections) == 64 * collection_num
            entry.append(packed_collections)

            data.append(entry)

    print(f"{data_file} parsed successfully!")
    os.chdir(cwd)
    return data


if __name__ == "__main__":
    # mainnet_idx = int(sys.argv[1])
    # for mainnet_idx in range(11, 14):
    #     data_path = f"../data/mainnet_{mainnet_idx}/"

    #     data = parse_data(data_path)
    #     start_height = data[0][0]
    #     conn = get_connection()
    #     table_name = create_table(conn, mainnet_idx, start_height)
    #     insert_table(conn, data, table_name)
    #     close_connection(conn)
    #     print(f"mainnet {mainnet_idx} insert accomplished!")

    conn = get_connection()
    # table_name = create_table_all_in_one(conn, 7601063)
    for mainnet_idx in range(14, 16):
        data_path = f"../data/mainnet_{mainnet_idx}/"
        data = parse_data(data_path)
        insert_table(conn, data, table_all_in_one)
        print(f"mainnet {mainnet_idx} insert accomplished!")
    close_connection(conn)
