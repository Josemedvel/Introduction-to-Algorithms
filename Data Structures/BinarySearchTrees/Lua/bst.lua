Node = {
    val = nil,
    left = nil,
    right = nil
}

function Node.new(num)
    local newNode = {}
    setmetatable(newNode, {__index  = Node})
    newNode.val = num
    return newNode
end

function Node:insert(num)
    if self.val == nil then
        self.val = num
    else
        if num < self.val then
            if self.left == nil then
                self.left = Node.new(num)
            else
                self.left:insert(num)
            end
        else
            if self.right == nil then
                self.right = Node.new(num)
            else
                self.right:insert(num)
            end
        end
    end
end

function Node:inOrder()
    if self == nil then
        return
    end
    
    if self.left ~= nil then
        self.left:inOrder()
    end
    io.write(self.val .. "\t")
    if self.right ~= nil then
        self.right:inOrder()
    end
end

function Node:preOrder()
    if self == nil then
        return
    end
    io.write(self.val .. "\t")
    if self.left ~= nil then
        self.left:preOrder()
    end
    if self.right ~= nil then
        self.right:preOrder()
    end
end

function Node:postOrder()
    if self == nil then
        return
    end
    if self.left ~= nil then
        self.left:postOrder()
    end
    if self.right ~= nil then
        self.right:postOrder()
    end
    io.write(self.val .. "\t")
end

function main()
    array = {2,1,5,4,6,3,7}
    node = Node.new(nil)
    for i,v in ipairs(array) do
        node:insert(v)
    end
    print("InOrder:")
    node:inOrder()
    print()
    print("PreOrder:")
    node:preOrder()
    print()
    print("PostOrder:")
    node:postOrder()
    print()
end

main()