#!/bin/bash

BASE_DIR=$(dirname "$0")

list_challenges() {
  echo "Available challenges:"
  for category in "$BASE_DIR"/*/; do
    category_name=$(basename "$category")
    for challenge in "$category"/*/; do
      challenge_name=$(basename "$challenge")
      if [ -f "$challenge"/*compose.y*ml ]; then
        echo "- $category_name/$challenge_name (docker-compose)"
      else
        echo "- $category_name/$challenge_name (no compose)"
      fi
    done
  done
}

manage_all_with_compose() {
  ACTION=$1
  echo "Performing '$ACTION' on all challenges with docker-compose.yml..."

  for category in "$BASE_DIR"/*/; do
    for challenge in "$category"/*/; do
      if [ -f "$challenge"/*compose.y*ml ]; then
        challenge_name=$(basename "$challenge")
        echo "Processing $challenge_name..."
        (
          cd "$challenge" || exit
          docker-compose "$ACTION" -d
        )
      else
        echo "Skipping $(basename "$challenge") (no compose)"
      fi
    done
  done
}

manage_single() {
  ACTION=$1
  CATEGORY=$2
  CHALLENGE=$3

  CHALLENGE_DIR="$BASE_DIR/$CATEGORY/$CHALLENGE"
  if [ -d "$CHALLENGE_DIR" ]; then
    if [ -f "$CHALLENGE_DIR"/*compose.y*ml ]; then
      echo "Performing '$ACTION' on $CATEGORY/$CHALLENGE (with docker-compose)..."
      (
        cd "$CHALLENGE_DIR" || exit
        docker-compose "$ACTION" -d
      )
    else
      echo "Challenge '$CATEGORY/$CHALLENGE' does not have a docker-compose.yml. Skipping..."
    fi
  else
    echo "Challenge '$CATEGORY/$CHALLENGE' not found!"
  fi
}

usage() {
  echo "Usage: $0 [command] [category] [challenge]"
  echo "Commands:"
  echo "  list                        List all challenges"
  echo "  up                          Start all challenges with docker-compose"
  echo "  down                        Stop all challenges with docker-compose"
  echo "  build                       Build all challenges with docker-compose"
  echo "  up [category] [challenge]   Start a specific challenge"
  echo "  down [category] [challenge] Stop a specific challenge"
  echo "  logs [category] [challenge] View logs of a specific challenge"
}

if [ $# -eq 0 ]; then
  usage
  exit 1
fi

COMMAND=$1
CATEGORY=$2
CHALLENGE=$3

case $COMMAND in
  list)
    list_challenges
    ;;
  up)
    if [ -z "$CATEGORY" ]; then
      manage_all_with_compose up
    else
      manage_single up "$CATEGORY" "$CHALLENGE"
    fi
    ;;
  down)
    if [ -z "$CATEGORY" ]; then
      manage_all_with_compose down
    else
      manage_single down "$CATEGORY" "$CHALLENGE"
    fi
    ;;
  build)
    if [ -z "$CATEGORY" ]; then
      manage_all_with_compose build
    else
      manage_single build "$CATEGORY" "$CHALLENGE"
    fi
    ;;
  logs)
    if [ -z "$CATEGORY" ] || [ -z "$CHALLENGE" ]; then
      echo "Specify a category and challenge to view logs!"
      usage
    else
      manage_single logs "$CATEGORY" "$CHALLENGE"
    fi
    ;;
  *)
    usage
    ;;
esac
