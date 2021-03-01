(6)打开TensorBoard流程
6.1 生成events文件

 writer = tf.summary.FileWriter("./convbp_filter_events", tf.get_default_graph())
writer.close()

6.2 生成tensorboard图： tensorboard --logdir=dir_to_events_file –port=port_number
6.3 在浏览器打开tensorboard图：网页地址加端口号（例10.2.5.242:6008）


