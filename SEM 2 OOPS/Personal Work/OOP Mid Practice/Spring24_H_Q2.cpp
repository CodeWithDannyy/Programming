#include<iostream>
using namespace std;

class Comment;

class Post
{
    private:
        int postID;
        string content;
        Comment* comments[10];
        int commentsCount;

    public:
        Post(int postID, string content) : postID(postID), content(content), commentsCount(0)
        {
            for(int i = 0; i < 10; i++)
                comments[i] = nullptr;
        }

        void addComment(Comment* comment)
        {
            if(commentsCount < 10)
            {
                comments[commentsCount++] = comment;
                cout << "Comment added successfully" << endl;
            }
            else
                cout << "Comment Limit of 10 Reached." << endl;
        }

        int getPostID() const { return postID; }
        string getContent() const { return content; }
};

class User
{
    private:
        int userID;
        string userName;
        Post* posts[10];
        int postsCount;
    
    public:
        User(int userID, string userName) : userID(userID), userName(userName), postsCount(0)
        {
            for(int i = 0; i < 10; i++)
                posts[i] = nullptr;
        }

        void createPost(Post* post)
        {
            if(postsCount < 10)
            {
                posts[postsCount++] = post;
                cout << "Post created successfully" << endl;
            }
            else
                cout << "Post Limit of 10 Reached." << endl;
        }

        void displayPosts()
        {
            if(postsCount == 0)
            {
                cout << userName << " has no posts" << endl;
                return;
            }

            cout << userName << "'s posts" << endl;
            for(int i = 0; i < postsCount; i++)
                cout << "Post ID: " << posts[i]->getPostID() << ", Content: " << posts[i]->getContent() << endl;
        }

        int getUserID() const { return userID; }
        string getUserName() const { return userName; }
};

class Comment
{
    private:
        int commentID;
        string content;
        User* author;

    public:
        Comment(int commentID, string content, User* author) : commentID(commentID), content(content), author(author) {}

        int getCommentID() const { return commentID; }
        string getContent() const { return content; }
        string getAuthor() const { return author->getUserName(); }
};

class SocialMediaPlatform
{
    private:
        User* users[10];
        int usersCount;
    
    public:
        SocialMediaPlatform() : usersCount(0)
        {
            for(int i = 0; i < 10; i++)
                users[i] = nullptr;
        }

        void registerUser(User* user)
        {
            if(usersCount < 10)
            {
                users[usersCount++] = user;
                cout << "User registered successfully" << endl;
            }
            else
                cout << "User Limit Reached" << endl;
        }

        void displayUser()
        {
            if(usersCount == 0)
            {
                cout << "No users registered" << endl;
                return;
            }
            
            cout << "Registered Users:" << endl;
            for(int i = 0; i < usersCount; i++)
            {
                cout << "ID : " << users[i]->getUserID() << endl;
                cout << "Name: " << users[i]->getUserName() << endl;
            }
        }
};

int main()
{
    SocialMediaPlatform platform;

    User user1(1, "Alice");
    User user2(2, "Bob");
    
    platform.registerUser(&user1);
    platform.registerUser(&user2);

   
    Post post1(101, "Hello, this is my first post!");
    user1.createPost(&post1);

    Post post2(102, "This is another post!");
    user2.createPost(&post2);

    
    Comment comment1(201, "This is another comment!", &user1);
    post1.addComment(&comment1);

   
    platform.displayUser();

    cout << "\nUser 1's posts:" << endl;
    user1.displayPosts();

    cout << "\nUser 2's posts:" << endl;
    user2.displayPosts();

    return 0;
}