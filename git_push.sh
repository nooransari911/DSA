ssh -T git@github.com
git add .
git remote set-url origin git@github.com:nooransari911/DSA.git
echo "Enter commit message:"
read commit_message
echo ""
echo "Starting commit;"
git commit -m "$commit_message"
echo ""
echo "Starting push;"
git push -u origin main
