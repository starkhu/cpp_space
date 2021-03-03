docker run -it \
    --name ubuntu_test \
    --network=host \
    --cap-add=sys_ptrace \
    -v /home/my_space:/my_space \
    my_ubuntu:v1 /bin/bash
