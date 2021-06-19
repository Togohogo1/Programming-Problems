Q = ''' !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'''
D = ''' !_#$%&-()*}w[vz0123456789SsW]VZ@AXJE>UIDCHTNMBRL"POYGK<QF:/\\=^{`axje.uidchtnmbrl'poygk,qf;?|+~'''

new = ""

for i in input():
    new += Q[D.index(i)]

print(new)
