def is_valid_ip(ipstr):
    iparr = ipstr.split(".")
    if len(iparr) != 4:
        return "NO"
    for i in iparr:
        if i.isdigit():
            i = int(i)
            if i < 0 or i > 255:
                return "NO"
        else:
            return "NO"
    return "YES"

if __name__ == '__main__':
    while True:
        try:
            ipstr = raw_input()
            print is_valid_ip(ipstr)
        except:
            break