# Check if a commit message was provided as an argument
if [ -z "$1" ]; then
    # If no commit message is provided, use the current date and time
    COMMIT_MSG="Update at $(date)"
else
    # Use the provided commit message
    COMMIT_MSG="$1"
fi

# Add all changes
git add .

# Commit changes with the provided message
git commit -m "$COMMIT_MSG"

# Push changes to the 'main' branch
git push origin main

# Print a success message
echo "Changes have been pushed to GitHub successfully!"