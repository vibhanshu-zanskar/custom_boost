#!/bin/bash

set -eu

echo "## RUN SCRIPT: Generating boost libs"

SCRIPT_PATH=$(realpath "$0")
REPO_PATH=$(dirname $(dirname $SCRIPT_PATH))
STAGING_AREA=${REPO_PATH}/staging/
mkdir -p ${STAGING_AREA}

BOOST_LIB_NAME=boost_1_81_0
echo "# Download boost archive ${BOOST_LIB_NAME}"
BOOST_HTTPS_PATH=https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/${BOOST_LIB_NAME}.tar.gz
wget -q --show-progress "${BOOST_HTTPS_PATH}" -P ${STAGING_AREA}
tar zxf ${STAGING_AREA}/${BOOST_LIB_NAME}.tar.gz -C ${STAGING_AREA}

BOOST_DIR=${STAGING_AREA}/${BOOST_LIB_NAME}

if [ ! -d ${BOOST_DIR} ]
then
    echo "${BOOST_DIR} not generated correctly"
    exit 1
fi

pushd ${BOOST_DIR}
mkdir -p build

echo "# Build Boost and bcp"
bash ./bootstrap.sh --prefix=${BOOST_DIR}/build
./b2
./b2 headers
./b2 install
./b2 tools/bcp

BCP_PATH=./dist/bin/bcp

if [ ! -f ${BCP_PATH} ]
then
    echo "${BCP_PATH} not generated correctly"
    exit 1
fi

OUTPUT_DIR=${REPO_PATH}/zr_boost_1_81
echo "# Run bcp: output dir ${OUTPUT_DIR}"
mkdir -p ${OUTPUT_DIR}
eval "${BCP_PATH} archive algortihm asio boost/circular_buffer.hpp boost/config.hpp container functional hana io iterator boost/lexical_cast.hpp mp11 boost/operators.hpp preprocessor process program_options system property_tree range boost/scope_exit.hpp date_time log interprocess serialization numeric ublas array test build bootstrap.sh boostcpp.jam boost-build.jam --namespace=zr_boost_1_81 --boost=${BOOST_DIR} ${OUTPUT_DIR}"

# Directory to be included to compiler include path:  ${BOOST_DIR}
# Directory to be included to linker library path:  ${BOOST_DIR}/stage/lib


