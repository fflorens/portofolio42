s = r"print('s = r\"' + s + '\"' + '\n\'\'\'com\'\'\'\ndef nothing():\n    pass\ndef main():\n    \'\'\'comment\'\'\'\n    nothing()\n    exec(s)\nmain()')"
'''com'''
def nothing():
    pass
def main():
    '''comment'''
    nothing()
    exec(s)
main()
