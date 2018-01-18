from os import system
i=5
if i >= 0:
    s = r"with open('Sully_'+str(i)+'.py', 'w') as f: f.write('from os import system\ni='+str(i-1)+'\nif i >= 0:\n    s = r\"' + s + '\"' + '\n    exec(s)\n    system(\"python3 Sully_\" + str(i) + \".py\")\n')"
    exec(s)
    system("python3 Sully_" + str(i) + ".py")
