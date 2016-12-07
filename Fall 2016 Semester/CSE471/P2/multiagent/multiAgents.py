# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
      A reflex agent chooses an action at each choice point by examining
      its alternatives via a state evaluation function.

      The code below is provided as a guide.  You are welcome to change
      it in any way you see fit, so long as you don't touch our method
      headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {North, South, West, East, Stop}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        #print [(legalMoves[i], scores[i]) for i in bestIndices]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood().asList()
        curFood = currentGameState.getFood().asList()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        ghostPos = [i.getPosition() for i in newGhostStates if not i.scaredTimer]
        scaredGhostPos = [i.getPosition() for i in newGhostStates if i.scaredTimer]

        foodEaten = len(curFood) - len(newFood)
        x, y = newPos
        distToClosestFood = min([abs(y-y1) + abs(x-x1) for x1, y1 in [i.getPosition() for i in newGhostStates] ])

        positions = ghostPos, newPos
        closestGhost = min([min(abs(y-y1), abs(x-x1)) for x1, y1 in ghostPos] or [0])
        if closestGhost > 3:
          closestGhost = 0
        else:
          closestGhost = 3 - closestGhost
        dead = closestGhost > 1
        closestScaredGhost = min([abs(y-y1) + abs(x-x1) for x1, y1 in scaredGhostPos] or [0])

        
        #magic numbers found by guess and check. 
        fear = 9
        hunger = 6
        score = -fear*closestGhost - hunger*distToClosestFood + successorGameState.getScore()
        "*** YOUR CODE HERE ***"
        return score

def scoreEvaluationFunction(currentGameState):
    """
      This default evaluation function just returns the score of the state.
      The score is the same one displayed in the Pacman GUI.

      This evaluation function is meant for use with adversarial search agents
      (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
      This class provides some common elements to all of your
      multi-agent searchers.  Any methods defined here will be available
      to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

      You *do not* need to make any changes here, but you can if you want to
      add functionality to all your adversarial search agents.  Please do not
      remove anything, however.

      Note: this is an abstract class: one that should not be instantiated.  It's
      only partially specified, and designed to be extended.  Agent (game.py)
      is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action from the current gameState using self.depth
          and self.evaluationFunction.

          Here are some method calls that might be useful when implementing minimax.

          gameState.getLegalActions(agentIndex):
            Returns a list of legal actions for an agent
            agentIndex=0 means Pacman, ghosts are >= 1

          gameState.generateSuccessor(agentIndex, action):
            Returns the successor game state after an agent takes an action

          gameState.getNumAgents():
            Returns the total number of agents in the game
        """
        "*** YOUR CODE HERE ***"
        a = self.getActionHelper(gameState, self.depth+1, 0)
        #print a
        return a[0]
    
    def getActionHelper(self, gameState, depth, agent): 
        #print agent
        if agent == 0:
          depth -= 1

        if depth<=0:
          #print self.evaluationFunction(gameState), "THIS ONE"
          #print gameState.state
          return (None, self.evaluationFunction(gameState))
        elif agent==0:
          action_state = [(action, self.getActionHelper(gameState.generateSuccessor(0, action), depth, agent+1)[1]) for action in gameState.getLegalActions(0)]
          #print action_state
          #print max(action_state or [(None, float("-inf"))], key=lambda x: x[1]), "max"
          if len(action_state) == 0:
            return (None, self.evaluationFunction(gameState))
          return max(action_state or [(None, float("-inf"))], key=lambda x: x[1])
        else:
          action_state = [(action, self.getActionHelper(gameState.generateSuccessor(agent, action), depth, (agent+1)%gameState.getNumAgents())[1]) for action in gameState.getLegalActions(agent)]
          #print action_state
          #print min(action_state or [(None, float("inf"))], key=lambda x: x[1]), "min"
          if len(action_state) == 0:
            return (None, self.evaluationFunction(gameState))
          return min(action_state or [(None, float("inf"))], key=lambda x: x[1])


class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        a = self.max_value(gameState, self.depth, float("-inf"), float("inf"), 0)
        #print a, "FINAL"
        return a[0]
    
    def min_value(self, gameState, depth, alpha, beta, agent):
      #print alpha, beta, "MIN"
      if depth<=0:
        return (None, self.evaluationFunction(gameState))
      hasChild = False
      value = float("inf")
      bestAction = None
      for action in gameState.getLegalActions(agent):
        hasChild = True
        if (agent+1)%gameState.getNumAgents() == 0:
          bestAction, value = min([(bestAction, value), (action, self.max_value(gameState.generateSuccessor(agent, action), depth-1, alpha, beta, 0)[1])], key=lambda x: x[1])
        else:
          bestAction, value = min([(bestAction, value), (action, self.min_value(gameState.generateSuccessor(agent, action), depth, alpha, beta, agent+1)[1])], key=lambda x: x[1])        
        beta = min(beta, value)
        if beta < alpha:
          return (bestAction, value)
      if not hasChild:
        return (None, self.evaluationFunction(gameState))
      return (bestAction, value)
        
    def max_value(self, gameState, depth, alpha, beta, agent):
      #print alpha, beta, "MAX"
      if depth<=0:
        return (None, self.evaluationFunction(gameState))
      hasChild = False
      value = float("-inf")
      bestAction = None
      for action in gameState.getLegalActions(agent):
        hasChild = True
        if (agent+1)%gameState.getNumAgents() == 0:
          bestAction, value = max([(bestAction, value), (action, self.max_value(gameState.generateSuccessor(agent, action), depth-1, alpha, beta, 0)[1])], key=lambda x: x[1])
        else:
          bestAction, value = max([(bestAction, value), (action, self.min_value(gameState.generateSuccessor(agent, action), depth, alpha, beta, agent+1)[1])], key=lambda x: x[1])        
        alpha = max(alpha, value)
        if alpha > beta:
          return (bestAction, value)
      if not hasChild:
        return (None, self.evaluationFunction(gameState))
      return (bestAction, value)

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
          Returns the expectimax action using self.depth and self.evaluationFunction

          All ghosts should be modeled as choosing uniformly at random from their
          legal moves.
        """
        "*** YOUR CODE HERE ***"
        util.raiseNotDefined()

    #NOT IMPLEMENTED YET
    def expect_value(self, gameState, depth, alpha, beta, agent):
      #print alpha, beta, "MIN"
      if depth<=0:
        return (None, self.evaluationFunction(gameState))
      hasChild = False
      value = float("inf")
      bestAction = None
      for action in gameState.getLegalActions(agent):
        hasChild = True
        if (agent+1)%gameState.getNumAgents() == 0:
          bestAction, value = min([(bestAction, value), (action, self.max_value(gameState.generateSuccessor(agent, action), depth-1, alpha, beta, 0)[1])], key=lambda x: x[1])
        else:
          bestAction, value = min([(bestAction, value), (action, self.min_value(gameState.generateSuccessor(agent, action), depth, alpha, beta, agent+1)[1])], key=lambda x: x[1])        
        beta = min(beta, value)
        if beta < alpha:
          return (bestAction, value)
      if not hasChild:
        return (None, self.evaluationFunction(gameState))
      return (bestAction, value)
        
    def max_value(self, gameState, depth, alpha, beta, agent):
      #print alpha, beta, "MAX"
      if depth<=0:
        return (None, self.evaluationFunction(gameState))
      hasChild = False
      value = float("-inf")
      bestAction = None
      for action in gameState.getLegalActions(agent):
        hasChild = True
        if (agent+1)%gameState.getNumAgents() == 0:
          bestAction, value = max([(bestAction, value), (action, self.max_value(gameState.generateSuccessor(agent, action), depth-1, alpha, beta, 0)[1])], key=lambda x: x[1])
        else:
          bestAction, value = max([(bestAction, value), (action, self.min_value(gameState.generateSuccessor(agent, action), depth, alpha, beta, agent+1)[1])], key=lambda x: x[1])        
        alpha = max(alpha, value)
        if alpha > beta:
          return (bestAction, value)
      if not hasChild:
        return (None, self.evaluationFunction(gameState))
      return (bestAction, value)

def betterEvaluationFunction(currentGameState):
    """
      Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
      evaluation function (question 5).

      DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"
    return currentGameState.getScore()

# Abbreviation
better = betterEvaluationFunction

