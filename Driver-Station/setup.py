#!/usr/bin/env python

from distutils.core import setup

setup(
    name='Driver-Station',
    version='0.1',
    description='Driver Station for the demo robot',
    author='Nam Tran',
    author_email='tranngocnam97@gmail.com',
    url='https://gw-robotics.github.io/Generic-Robot-Platform',
    tests_require=['pytest'],
    install_requires=[],
    packages=['driver-station'],
    include_package_data= True,
    platforms='any',
    test_suite='driver-station.test.test_driver_station',
    extras_require={
        'testing': ['pytest'],
    },
)

