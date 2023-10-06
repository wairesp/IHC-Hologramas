# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/mp11
    REF boost-1.83.0
    SHA512 d9db5afc318a0e28649d447b6c08fd0ee446bbc3b0d394607cf0430fd55350ea5dd75769bdb461abd39db6207dec5e76c4c468b9b6925d9608a62b7fdfdcfa05
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})