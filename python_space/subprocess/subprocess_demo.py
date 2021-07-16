import subprocess

subprocess.run(['df', '-h'])
subprocess.run('df -h | grep /dev', shell=True)

#create a new process
res = subprocess.Popen("sleep 10;echo 'hello'", shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
res.terminate()
print(res.poll())
res.wait()
print(res.pid)
print(res.stdout.read())
print("completed")
