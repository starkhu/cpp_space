从官网拉去ubuntu的docker镜像

docker pull ubuntu:latest





显示系统安装的docker镜像

镜像相当于一份未运行代码的代码，

docker images



显示docker的容器

docker ps -a



启动docker

docker run -it /bin/bash



启动container

docker start container_id



#连接到正在运行的container

docker attach container_name



关闭docker

docker stop container_id



删除docker

docker rm container_id





// 重新进入docker

 docker exec -it container_id  bash

