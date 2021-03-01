显示系统安装的docker镜像

镜像相当于一份未运行代码的代码，

docker images



显示docker的容器

docker ps -a



启动docker

docker run -it /bin/bash



关闭docker

docker stop container_id



删除docker

docker rm container_id





// 重新进入docker

docker start container_id

 docker exec -it container_id  bash


