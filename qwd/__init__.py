# import argparse
# import os

# from mykit import lock_version as lock_mykit_version
# from mykit.kit.pLog import pL
# from mykit.myprog import MyProg
# # from qwd.__myprog__.mykit.kit.pLog import pL
# # from mykit.kit.shell import run

# from pyggc import lock_version as lock_pyggc_version


# ## This should be the only place where dependency versions are written
# mp = MyProg(
#     dist_dir=os.path.dirname(__file__),
#     dependencies={
#         'mykit': '10.0.0',
#         'pyggc': '1.1.0',
#     }
# )

# ## Double-check to make sure the versions match, in case any errors happen.
# lock_mykit_version(mp.dependencies['mykit'])
# lock_pyggc_version(mp.dependencies['pyggc'])


# def parse():

#     ## Main parser
#     p = argparse.ArgumentParser()

#     ## Global optional args
#     p.add_argument('-L', '--loglevel', default='info')

#     ## Subparsers
#     s = p.add_subparsers(dest='cmd')

#     ## cmd
#     s.add_parser('q')

#     return p.parse_args()


# def main():
#     pL.debug(f'Running')

#     CWD = os.getcwd()
#     pL.debug(f'CWD: {repr(CWD)}.')

#     args = parse()

#     if args.cmd == 'q':
#         print('hi 12345')


# if __name__ == '__main__':

#     ## Before publishing to production,
#     ## run this file during the build process to bundle the dependencies.
#     mp.bundle_the_dependencies()


from mykit import __version__
def main():
    print(__version__)
    print('12313213123')
    