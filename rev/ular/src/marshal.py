import marshal

pyc_path = "__pycache__/challenge.cpython-312.pyc"

with open(pyc_path, "rb") as f:
    f.read(16)
    code_object = marshal.load(f)

with open("challenge.marshal", "wb") as f:
    f.write(marshal.dumps(code_object))

