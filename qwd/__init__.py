import argparse
import os

from mykit.kit.pLog import pL
# from mykit.kit.shell import run


def parse():

    ## Main parser
    p = argparse.ArgumentParser()

    ## Global optional args
    p.add_argument('-L', '--loglevel', default='info')

    ## Subparsers
    s = p.add_subparsers(dest='cmd')

    ## cmd
    s.add_parser('q')

    return p.parse_args()


def main():
    pL.debug(f'Running')

    CWD = os.getcwd()
    pL.debug(f'CWD: {repr(CWD)}.')

    args = parse()

    if args.cmd == 'q':
        print('hi 1234')
