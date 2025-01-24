import marshal

f = open("ular", 'rb')
s = f.read()
f.close()

marshal_code = marshal.loads(s)
exec(marshal_code)
