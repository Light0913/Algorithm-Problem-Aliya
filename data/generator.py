from cyaron import *
from os import *

def hack(n, t, w, id):
    m = n
    data = IO(file_prefix = "aliya", data_id = id)
    data.input_writeln(n, m, t)
    for i in range(2, n - 1):
        if i == 2:
            data.input_writeln(i, i + 1, 1)
        else:
            data.input_writeln(i, i + 1, w)
    data.input_writeln(n - 1, 2, w)
    data.input_writeln(2, n, w)
    data.input_writeln(1, 2, w)

    data.output_gen("std.exe")

# hack 1
# hack(50, 30, 0)

# hack 2
# hack(200, 300, 1)

# hack 3
# hack(500, 100, 0)

# hack 4
# hack(100000, 50000, 1)

def is_not_zero(id):
    return not system("check_output.exe < aliya" + str(id) + ".in")
def valid(id):
    return not system("validator.exe < aliya" + str(id) + ".out")

for id in range(25, 26):
    n = m = t = 0
    if (id >= 1 and id <= 3):
        if (id == 1):# w 远大于 t
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)
                
                n = randint(40, 50)
                m = randint(90, 100)
                t = 1000
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (2, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        elif (id == 2):# w 全为 0
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = randint(40, 50)
                m = randint(90, 100)
                t = 1000
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (0, 0), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        else:# 环
            data = IO(file_prefix = "aliya", data_id = id)

            print("#" + str(id) + ": ", end = "")
            hack(50, 1000, 1, id)
            print("Success!")

    elif (id >= 4 and id <= 7):
        if (id == 4):# w 全为 0
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = randint(180, 200)
                m = randint(950, 1000)
                t = randint(200, 300)
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (0, 0), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                break
            print("Success!")
        elif (id == 5):# t = 0
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = randint(180, 200)
                m = randint(950, 1000)
                t = 0
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (100000, 1000000), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")
                data.close()
                break
            print("Success!")
        elif (id == 6):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = randint(180, 200)
                m = randint(950, 1000)
                t = 299
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (3, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        else:# 环
            data = IO(file_prefix = "aliya", data_id = id)
            print("#" + str(id) + ": ", end = "")
            hack(200, 30000, 1000000, id)
            print("Success!")

    elif (id >= 8 and id <= 13):
        if (id == 8):# w 全为 0
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = randint(490, 500)
                m = randint(7950, 8000)
                t = randint(90, 100)
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (0, 0), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                break
            print("Success!")
        elif (id == 9):# w 远小于 t
            print("#" + str(id) + ": ", end = "")
            while True:
                break
                data = IO(file_prefix = "aliya", data_id = id)

                n = randint(490, 500)
                m = randint(7950, 8000)
                t = randint(90, 100)
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (0, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        elif (id == 10):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = 500
                m = 8000
                t = 100
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (3, 5), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        elif (id >= 11 and id <= 12):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = 500
                m = 8000
                t = 100
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (0, 100), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        else:# 稠密图
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                n = 500
                m = 8000
                t = 99
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (2, 2), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")   

    elif (id >= 14 and id <= 20):
        n = randint(49900, 50000)
        m = randint(59900, 60000)
        if (id == 14):# w 远小于 t
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                t = 79
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (2, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        elif (id == 15):# 稀疏图、w 大于 t
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)

                t = 80
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (3, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        elif (id == 16):# hack spfa
            print("#" + str(id) + ": ", end = "")
            while True:
                break
                data = IO(file_prefix = "aliya", data_id = id)

                n = 40000
                m = int(n * 1.5)
                t = 80  
                data.input_writeln(n, m, t)

                G = Graph.hack_spfa(n, weight_limit = (1000000, 1000000), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        elif (id == 17):
            print("#" + str(id) + ": ", end = "")
            while True:
                break
                data = IO(file_prefix = "aliya", data_id = id)

                t = 79
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (2, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                system("WA.exe < aliya17.in > WA.out")
                if (system("checker aliya17.in WA.out aliya17.out")):
                    break
            print("Success!")
        elif (id == 18):# 稠密图、w 远小于 t
            print("#" + str(id) + ": ", end = "")
            while True:
                break
                data = IO(file_prefix = "aliya", data_id = id)

                t = randint(70, 80)
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (2, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        elif (id == 19):# 链
            print("#" + str(id) + ": ", end = "")
            while True:
                break
                data = IO(file_prefix = "aliya", data_id = id)

                n = 60000
                m = n - 1
                t = 80
                data.input_writeln(n, m, t)

                G = Graph.chain(n, weight_limit = (1000000, 1000000), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
        else:# 稠密图
            print("#" + str(id) + ": ", end = "")
            hack(60000, 80, 0, 20)
            print("Success!")
    elif (id == 21):
        n = randint(19900, 29000)
        m = randint(90000, 100000)
        if (1):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)


                t = 50
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (2, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
    elif (id == 22):
        n = randint(89900, 90000)
        m = randint(99000, 100000)
        if (1):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)


                t = 49
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (2, 3), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
    elif (id == 23):
        n = randint(49900, 59000)
        m = randint(90000, 100000)
        if (1):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)


                t = 49
                data.input_writeln(n, m, t)

                G = Graph.UDAG(n, m, weight_limit = (3, 5), self_loop = False, repeated_edges = False)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
    elif (id == 24):
        n = randint(9900, 10000)
        m = randint(90000, 100000)
        if (1):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)


                t = 49

                G = Graph.UDAG(n, m, weight_limit = (0, 1), self_loop = False, repeated_edges = False)
                m += 1
                data.input_writeln(n, m, t)

                data.input_writeln(G)
                data.input_writeln(1, n, 114514)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
    elif (id == 31):
        n = randint(50000, 60000)
        m = randint(90000, 100000)
        if (1):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)


                t = 49

                G = Graph.UDAG(n, m, weight_limit = (2, 3), self_loop = False, repeated_edges = False)
                data.input_writeln(n, m, t)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                system("WA.exe < aliya31.in > WA.out")
                if (system("checker aliya31.in WA.out aliya31.out")):
                    break
            print("Success!")
    elif (id == 25):
        n = 50000
        m = randint(90000, 100000)
        if (1):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)


                t = 49

                G = Graph.UDAG(n, m, weight_limit = (2, 2), self_loop = False, repeated_edges = False)
                data.input_writeln(n, m, t)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
    elif (id == 25):
        break
        print("#" + str(id) + ": ", end = "")
        hack(100000, 50, 0, 25)
        print("Success!")
    elif (id == 33):
        n = 12000
        m = 100000
        if (1):
            print("#" + str(id) + ": ", end = "")
            while True:
                data = IO(file_prefix = "aliya", data_id = id)


                t = 49

                G = Graph.UDAG(n, m, weight_limit = (2, 2), self_loop = False, repeated_edges = False)
                data.input_writeln(n, m, t)

                data.input_writeln(G)

                data.output_gen("std.exe")

                data.close()
                if (is_not_zero(id)):
                    break
            print("Success!")
for id in range(25, 26):
    print("Shuffle #" + str(id) + ": ", end = "")
    system("shuffle.exe < aliya" + str(id) + ".in > shuffled.txt")
    system("copy shuffled.txt aliya" + str(id) + ".in")
    print("Success!")

