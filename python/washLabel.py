def washLabel(html,label):
    html = html[html.find("<body"):html.rfind("</body>")]
    res = ""
    while "<"+label in html:
        html = html[html.find('<'):-1]
        html = html[html.find('>'):-1]
        res += html[1:html.find('<')-1]
    return res

# if __name__ == "__main__":
    # main()