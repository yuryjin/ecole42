FROM debian

MAINTAINER zlucan <zlucan@student.21-school.ru>

RUN apt-get update && apt-get install -y cowsay fortune lolcat

ENTRYPOINT /usr/games/fortune | /usr/games/cowsay | /usr/games/lolcat

# How to build it?
# docker build -t a00 .

# How to run it?
# docker run --rm -ti a00