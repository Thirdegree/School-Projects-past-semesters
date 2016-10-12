type Weight = Int
type Vertex = Int
data Edge   = ((Vertex, Vertex), Weight)    deriving Read, Show
data Graph  = ([Vertex], [Edge])            deriving Read, Show
data AdjList= [(Vertex, Vertex, Weight)]    deriving Read, Show
