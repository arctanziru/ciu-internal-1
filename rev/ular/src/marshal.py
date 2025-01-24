import marshal

pyc_path = "__pycache__/ular.cpython-310.pyc"

with open(pyc_path, "rb") as f:
    f.read(16)
    code_object = marshal.load(f)

with open("ular", "wb") as f:
    f.write(marshal.dumps(code_object))

