FROM python:3.10.6

MAINTAINER "Norton_Lin <norton@bupt.edu.cn>"
WORKDIR /usr/src/compiler
#   基本环境搭建
RUN apt-get update
RUN apt-get install -y
RUN apt-get update -y
RUN apt-get install wget -y
RUN apt-get install build-essential -y
RUN apt-get install flex -y
RUN apt-get install bison -y
RUN apt-get install clang -y
RUN apt-get install llvm-11 -y
RUN pip install sanic
COPY . .
EXPOSE 8888
CMD ["sh","process.sh"];["make"];["python3", "server.py" ] 
ENV DEBIAN_FRONTEND noninteractive
