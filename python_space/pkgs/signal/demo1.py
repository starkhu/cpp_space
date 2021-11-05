import os
import signal
import time

# 定义一个信号处理函数，该函数打印收到的信号，然后raise IOError
def handler(signum, frame):
    print('Signal handler called with signal', signum)
    raise IOError("Couldn't open device!")

# 对SIGALRM(终止)设置处理的handler, 然后设置定时器，5秒后触发SIGALRM信号
signal.signal(signal.SIGALRM, handler)
signal.alarm(5)

# This open() may hang indefinitely
fd = os.open('test.txt', os.O_RDWR)
time.sleep(6)
signal.alarm(0)
