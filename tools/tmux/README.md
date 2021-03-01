(4)tmux的使用
 默认前缀键prefix：ctrl+b（同时按）

4.2 开始创建会话： tmux new -s session_name

4.3 再创建一个会话：prefix c (先后按)

4.4 切换窗口：prefix n (n表示要切换到的窗口top)

4.5 关闭窗口：prefix &

4. 5 将会话放到后台执行：prefix d  (此时电脑可以终端与服务器之间的联系)

4.6 恢复后台执行的会话： tmux ls (查看当前会话情况)

                                     tmux a -t session_name



4.7 关闭当前会话：tmux kill-session -t session_name

4.8 关闭所有会话：tmux kill-server

4.9 重命名会话名：tmux rename -t old_name new_name

4.10 翻看终端页面：ctrl +b, [， 退出：q.
