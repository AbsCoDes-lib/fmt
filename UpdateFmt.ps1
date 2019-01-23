
# Download files from https://github.com/fmtlib/fmt
$Version="5.3.0"
docker run -it --rm -e http_proxy=${Env:\HTTP_PROXY} -e https_proxy=${Env:\HTTPS_PROXY} -v $PSScriptRoot/include/:/data craftdock/alpine-data gh-downloader -u fmtlib -r fmt -b $Version -p include -o ./
docker run -it --rm -e http_proxy=${Env:\HTTP_PROXY} -e https_proxy=${Env:\HTTPS_PROXY} -v $PSScriptRoot/src/fmt/:/data craftdock/alpine-data gh-downloader -u fmtlib -r fmt -b $Version -p src -o ./
