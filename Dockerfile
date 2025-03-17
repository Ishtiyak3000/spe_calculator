FROM ubuntu:latest
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libgtest-dev 
WORKDIR /app
COPY . .
RUN rm -rf CMakeCache.txt CMakeFiles/
RUN cmake . && make
CMD ["./calculator"]


