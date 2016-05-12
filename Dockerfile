FROM ubuntu:latest

RUN apt-get update -qq && apt-get upgrade -y && apt-get install -y build-essential
RUN apt-get install -y cmake libgtest-dev

# ----------- Build gtest ------------
RUN cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make && \
    cp *.a /usr/lib
# ------------------------------------

RUN apt-get install -y vim
ENV APP_HOME /kata

RUN mkdir $APP_HOME

WORKDIR $APP_HOME
ADD . $APP_HOME/
