uniform bool condition
p1 = ftransform
p2 = gl_ModelViewProjectionMatrix * gl_Vertex
a b = if b then p1 else p2
gl_Position = a condition
