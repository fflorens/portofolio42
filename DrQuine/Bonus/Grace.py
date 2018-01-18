s = r"with open('Grace_kid.py', 'w') as f: f.write('s = r\"' + s + '\"' + '\n\'\'\'com\'\'\'\nt=lambda x:exec(x)\nt(s)\n')"
'''com'''
t=lambda x:exec(x)
t(s)
