
# Download files from https://github.com/fmtlib/fmt
docker run -it --rm -e http_proxy=${Env:\HTTP_PROXY} -e https_proxy=${Env:\HTTPS_PROXY} -v $PSScriptRoot/include/:/data craftdock/alpine-data gh-downloader -u fmtlib -r fmt -p include -o ./
docker run -it --rm -e http_proxy=${Env:\HTTP_PROXY} -e https_proxy=${Env:\HTTPS_PROXY} -v $PSScriptRoot/src/fmt/:/data craftdock/alpine-data gh-downloader -u fmtlib -r fmt -p src -o ./
