def per( p,  up) :
        if (up=="") :
            print(p)
            return
        ch = up[0]
        i = 0
        while (i <= len(p)) :
            f = p[0:i]
            s = p[i:len(p)]
            per(f + str(ch) + s, up[1:])
            i += 1

if __name__ == "__main__":
    string=input("Enter the String: ")
    print(per("",string))