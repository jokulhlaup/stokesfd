function flow_stencil(n)
    dx=1/n
    dx2=dx*dx
    center = zeros(n*n)
    center[1:n] = 1.
    center[n+1:n*n-n] = -2/dx2
    left = zeros((n-1)^2)
    left
